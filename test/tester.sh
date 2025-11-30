#!/bin/bash

# Bash 3.2 compatible test runner
# Exit on any error in pipelines
set -o pipefail

# ANSI color codes
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[0;33m'
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
    # macOS - updated to 11.0 to avoid deprecation warnings
    NASM_FORMAT="macho64"
    LD_FLAGS="-macos_version_min 11.0 -no_pie"
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
        [ -f "$test_file" ] || continue  # Skip if no files match
        
        dir_total_tests=$((dir_total_tests + 1))
        local test_name=$(basename "$test_file" .c)

        # Extract the expected output from the comment at the beginning of the file
        expected_output=$(sed -n '/\/\*/,/\*\//p' "$test_file" | grep -v '/\*\|\*/')

        # Determine the compiler command based on the directory name
        if [ "$test_dir" = "ast" ]; then
            actual_output=$(../cmake-build-debug/compiler "$test_file" -ast 2>&1)
        elif [ "$test_dir" = "lexer" ]; then
            actual_output=$(../cmake-build-debug/compiler "$test_file" -lexer 2>&1)
        else
            actual_output=$(../cmake-build-debug/compiler "$test_file" 2>&1)
            
            # For code generation tests, compile and run
            if [ "$test_dir" = "code_gen" ]; then
                # Check if assembly was generated
                if [ -f "./output.asm" ]; then
                    # Assemble (suppress output on success)
                    if nasm -f $NASM_FORMAT ./output.asm -o ./output.o 2>/dev/null; then
                        # Link (suppress output on success)
                        if ld -o ./output ./output.o $LD_FLAGS 2>/dev/null; then
                            chmod +x ./output 2>/dev/null
                            # Run the compiled program
                            actual_output=$($ARCH_CMD ./output 2>&1)
                        else
                            actual_output="[LINK ERROR] Failed to link executable"
                        fi
                    else
                        actual_output="[ASSEMBLY ERROR] Failed to assemble output.asm"
                    fi
                    # Cleanup
                    rm -f ./output ./output.asm ./output.o 2>/dev/null
                else
                    actual_output="[COMPILER ERROR] No assembly output generated"
                fi
            fi
        fi

        # Compare the expected and actual output
        if [ "$expected_output" = "$actual_output" ]; then
            dir_passed_tests=$((dir_passed_tests + 1))
        else
            failed_tests+=("$test_name")
            
            # Store failure details for optional verbose output
            if [ -n "$VERBOSE" ]; then
                echo -e "${YELLOW}Test: $test_name${NC}"
                echo "Expected:"
                echo "$expected_output"
                echo "Actual:"
                echo "$actual_output"
                echo "---"
            fi
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
    passed="${result_passed[$i]}"
    total="${result_total[$i]}"
    name="${result_names[$i]}"
    
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
    echo -e "${GREEN}✓ All tests passed!${NC}"
    exit 0
else
    echo -e "\nOverall: ${RED}$total_passed/$total_tests${NC}"
    failed_count=$((total_tests - total_passed))
    echo -e "${RED}✗ $failed_count test(s) failed${NC}"
    echo ""
    echo "Tip: Set VERBOSE=1 to see detailed failure output"
    echo "     VERBOSE=1 ./tester.sh"
    exit 1
fi
