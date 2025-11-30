#!/bin/bash

# Bash 3.2 compatible test runner
# Exit on any error in pipelines
set -o pipefail

# ANSI color codes
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # No Color

# Simple arrays for storing results (bash 3.2 compatible)
result_names=()
result_passed=()
result_total=()

total_passed=0
total_tests=0

# Detect platform
detect_platform() {
    local uname_out="$(uname -s)"
    case "${uname_out}" in
        Linux*)     echo "Linux";;
        Darwin*)    echo "Darwin";;
        CYGWIN*)    echo "Cygwin";;
        MINGW*)     echo "MinGW";;
        *)          echo "Unknown"
    esac
}

PLATFORM=$(detect_platform)

# Set platform-specific build commands
if [ "$PLATFORM" = "Darwin" ]; then
    # macOS
    NASM_FORMAT="macho64"
    LD_FLAGS="-macos_version_min 10.7 -no_pie"
    ARCH_CMD="arch -x86_64"
else
    # Linux/Cygwin/MinGW
    NASM_FORMAT="elf64"
    LD_FLAGS="-no-pie"
    ARCH_CMD=""
fi

# Function to run tests in a given directory
run_tests() {
    local test_dir=$1
    local dir_total_tests=0
    local dir_passed_tests=0
    local failed_tests=()

    # Loop through all .c files in the test directory
    for test_file in "$test_dir"/*.c; do
        dir_total_tests=$((dir_total_tests + 1))

        # Extract the expected AST from the comment at the beginning of the file
        expected_ast=$(sed -n '/\/\*/,/\*\//p' "$test_file" | grep -v '/\*\|\*/')

        # Determine the compiler command based on the directory name
        if [ "$test_dir" = "ast" ]; then
            actual_ast=$(../cmake-build-debug/compiler "$test_file" -ast 2>&1)
        elif [ "$test_dir" = "lexer" ]; then
            actual_ast=$(../cmake-build-debug/compiler "$test_file" -lexer 2>&1)
        else
            actual_ast=$(../cmake-build-debug/compiler "$test_file" 2>&1)
            if [ "$test_dir" = "code_gen" ]; then
              nasm -f $NASM_FORMAT ./output.asm -o ./output.o 2>&1
              ld -o ./output ./output.o $LD_FLAGS 2>&1
              chmod +x ./output
              actual_ast=$($ARCH_CMD ./output 2>&1)
              rm -f ./output ./output.asm ./output.o
            fi
        fi

        # Compare the expected and actual AST
        if [ "$expected_ast" = "$actual_ast" ]; then
            dir_passed_tests=$((dir_passed_tests + 1))
        else
            failed_tests+=("$(basename "$test_file" .c)")
        fi
    done

    # Store results in indexed arrays (bash 3.2 compatible)
    result_names+=("$test_dir")
    result_passed+=("$dir_passed_tests")
    result_total+=("$dir_total_tests")
    
    total_passed=$((total_passed + dir_passed_tests))
    total_tests=$((total_tests + dir_total_tests))

    # Display failed tests, if any
    if [ ${#failed_tests[@]} -ne 0 ]; then
        echo -e "${RED}Failed tests in $test_dir:${NC}"
        for test in "${failed_tests[@]}"; do
            echo "  - $test"
        done
        echo
    fi
}

# List of directories to run tests in
test_dirs=("lexer" "lexing_error" "ast" "parsing_error" "name_analysis" "type_analysis" "code_gen")

# Loop through each directory in the list and run tests
for dir in "${test_dirs[@]}"; do
    run_tests "$dir"
done

# After running all tests, print summary table
echo -e "\nSummary Table:"
echo "--------------------"
printf "%-15s | %s\n" "Directory" "Passed/Total"
echo "--------------------"

# Print results from indexed arrays
for i in "${!result_names[@]}"; do
    local passed="${result_passed[$i]}"
    local total="${result_total[$i]}"
    local name="${result_names[$i]}"
    
    if [ "$passed" -eq "$total" ]; then
        printf "%-15s | ${GREEN}%s/%s${NC}\n" "$name" "$passed" "$total"
    else
        printf "%-15s | ${RED}%s/%s${NC}\n" "$name" "$passed" "$total"
    fi
done
echo "--------------------"

# Determine exit code based on test results
if [ "$total_passed" -eq "$total_tests" ]; then
    echo -e "\nOverall: ${GREEN}$total_passed/$total_tests${NC}"
    exit 0
else
    echo -e "\nOverall: ${RED}$total_passed/$total_tests${NC}"
    echo ""
    echo "TESTS FAILED: $((total_tests - total_passed)) of $total_tests tests failed"
    exit 1
fi
