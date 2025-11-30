#!/bin/bash

# Comprehensive Test Runner for nanoC Compiler
# Based on Comprehensive Testing Methodology v2.0

# ANSI color codes
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
NC='\033[0m' # No Color

# Get script directory
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
COMPILER="${SCRIPT_DIR}/../../cmake-build-debug/compiler"

# Check if compiler exists
if [ ! -f "$COMPILER" ]; then
    echo -e "${YELLOW}Warning: Compiler not found at $COMPILER${NC}"
    echo "Please build the compiler first or update the path."
    echo "Looking for alternative paths..."

    # Try alternative paths
    for alt_path in \
        "${SCRIPT_DIR}/../../build/compiler" \
        "${SCRIPT_DIR}/../../compiler" \
        "${SCRIPT_DIR}/../../../cmake-build-debug/compiler"; do
        if [ -f "$alt_path" ]; then
            COMPILER="$alt_path"
            echo -e "${GREEN}Found compiler at: $COMPILER${NC}"
            break
        fi
    done

    if [ ! -f "$COMPILER" ]; then
        echo -e "${RED}Error: Could not find compiler. Exiting.${NC}"
        exit 1
    fi
fi

# Arrays to store results
declare -A results
total_passed=0
total_tests=0

# Function to run tests in a given directory
run_tests() {
    local test_dir=$1
    local test_type=$2
    local dir_total_tests=0
    local dir_passed_tests=0
    local failed_tests=()

    # Check if directory exists and has .c files
    if [ ! -d "$test_dir" ] || [ -z "$(ls -A "$test_dir"/*.c 2>/dev/null)" ]; then
        return
    fi

    echo -e "\n${BLUE}Testing: $test_dir${NC}"

    # Loop through all .c files in the test directory
    for test_file in "$test_dir"/*.c; do
        if [ ! -f "$test_file" ]; then
            continue
        fi

        dir_total_tests=$((dir_total_tests + 1))

        # Extract the expected output from the comment at the beginning of the file
        expected_output=$(sed -n '/\/\*/,/\*\//p' "$test_file" | grep -v '\/\*\|\*\/')

        # Determine the compiler command based on the test type
        case "$test_type" in
            "lexer")
                actual_output=$("$COMPILER" "$test_file" -lexer 2>&1)
                ;;
            "ast"|"parser")
                actual_output=$("$COMPILER" "$test_file" -ast 2>&1)
                ;;
            "code_gen"|"integration"|"edge_cases")
                actual_output=$("$COMPILER" "$test_file" 2>&1)
                if [ $? -eq 0 ] && [ -f "./output.asm" ]; then
                    # Try to assemble and run (platform-specific)
                    if command -v nasm &> /dev/null; then
                        nasm -f elf64 ./output.asm -o ./output.o 2>/dev/null || \
                        nasm -f macho64 ./output.asm -o ./output.o 2>/dev/null

                        if [ -f "./output.o" ]; then
                            if command -v ld &> /dev/null; then
                                ld -o ./output ./output.o 2>/dev/null || \
                                ld -o ./output ./output.o -macosx_version_min 10.7 -no_pie 2>/dev/null
                            elif command -v gcc &> /dev/null; then
                                gcc -nostdlib -o ./output ./output.o 2>/dev/null
                            fi

                            if [ -f "./output" ]; then
                                chmod +x ./output
                                if command -v arch &> /dev/null; then
                                    actual_output=$(arch -x86_64 ./output 2>&1) || actual_output=$(./output 2>&1)
                                else
                                    actual_output=$(./output 2>&1)
                                fi
                            fi
                        fi
                    fi
                    rm -f ./output ./output.asm ./output.o
                fi
                ;;
            *)
                # For semantic tests (name_analysis, type_analysis, error_recovery)
                actual_output=$("$COMPILER" "$test_file" 2>&1)
                ;;
        esac

        # Compare the expected and actual output
        if [ "$expected_output" = "$actual_output" ]; then
            dir_passed_tests=$((dir_passed_tests + 1))
            echo -e "  ${GREEN}PASS${NC}: $(basename "$test_file")"
        else
            failed_tests+=("$(basename "$test_file" .c)")
            echo -e "  ${RED}FAIL${NC}: $(basename "$test_file")"
            if [ -n "$VERBOSE" ]; then
                echo "    Expected: $expected_output"
                echo "    Actual:   $actual_output"
            fi
        fi
    done

    # Store results
    results[$test_dir]="$dir_passed_tests/$dir_total_tests"
    total_passed=$((total_passed + dir_passed_tests))
    total_tests=$((total_tests + dir_total_tests))

    # Display summary for this directory
    if [ ${#failed_tests[@]} -ne 0 ]; then
        echo -e "  ${RED}Failed tests:${NC}"
        for test in "${failed_tests[@]}"; do
            echo "    - $test"
        done
    fi
}

# Print header
echo "=============================================="
echo "  nanoC Compiler Comprehensive Test Suite"
echo "  Based on Comprehensive Testing Methodology"
echo "=============================================="
echo ""
echo "Compiler: $COMPILER"
echo ""

# Run tests in bottom-up order (as per Comprehensive Testing Methodology)
echo -e "${BLUE}=== Level 1: Lexer Tests (No Dependencies) ===${NC}"
run_tests "${SCRIPT_DIR}/lexer" "lexer"

echo -e "\n${BLUE}=== Level 2: Parser Tests (Depends on Lexer) ===${NC}"
run_tests "${SCRIPT_DIR}/parser" "ast"

echo -e "\n${BLUE}=== Level 3: Name Analysis Tests (Depends on Parser) ===${NC}"
run_tests "${SCRIPT_DIR}/name_analysis" "semantic"

echo -e "\n${BLUE}=== Level 4: Type Analysis Tests (Depends on Name Analysis) ===${NC}"
run_tests "${SCRIPT_DIR}/type_analysis" "semantic"

echo -e "\n${BLUE}=== Level 5: Code Generation Tests (Depends on Type Analysis) ===${NC}"
run_tests "${SCRIPT_DIR}/code_gen" "code_gen"

echo -e "\n${BLUE}=== Level 6: Integration Tests (Full Pipeline) ===${NC}"
run_tests "${SCRIPT_DIR}/integration" "integration"

echo -e "\n${BLUE}=== Edge Case Tests ===${NC}"
run_tests "${SCRIPT_DIR}/edge_cases" "edge_cases"

echo -e "\n${BLUE}=== Error Recovery Tests ===${NC}"
run_tests "${SCRIPT_DIR}/error_recovery" "semantic"

# Print summary table
echo -e "\n=============================================="
echo "                  SUMMARY"
echo "=============================================="
printf "%-25s | %s\n" "Test Category" "Passed/Total"
echo "----------------------------------------------"

for dir in "lexer" "parser" "name_analysis" "type_analysis" "code_gen" "integration" "edge_cases" "error_recovery"; do
    full_path="${SCRIPT_DIR}/${dir}"
    if [ -n "${results[$full_path]}" ]; then
        IFS='/' read -r passed total <<< "${results[$full_path]}"
        if [ "$passed" -eq "$total" ]; then
            printf "%-25s | ${GREEN}%s${NC}\n" "$dir" "${results[$full_path]}"
        else
            printf "%-25s | ${RED}%s${NC}\n" "$dir" "${results[$full_path]}"
        fi
    fi
done

echo "----------------------------------------------"

# Color the overall result
if [ "$total_passed" -eq "$total_tests" ]; then
    echo -e "Overall: ${GREEN}$total_passed/$total_tests${NC}"
else
    echo -e "Overall: ${RED}$total_passed/$total_tests${NC}"
fi

# Calculate coverage percentage
if [ "$total_tests" -gt 0 ]; then
    coverage=$((total_passed * 100 / total_tests))
    echo -e "Coverage: ${coverage}%"
fi

echo ""
echo "=============================================="
echo "  Test run completed at $(date)"
echo "=============================================="

# Exit with appropriate code
if [ "$total_passed" -eq "$total_tests" ]; then
    exit 0
else
    exit 1
fi
