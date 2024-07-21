#!/usr/bin/env python3

import unittest
import os
import sys
import importlib.util

def load_tests_from_file(file_path):
    # Add the directory containing the test file to sys.path
    dir_path = os.path.dirname(file_path)
    if dir_path not in sys.path:
        sys.path.insert(0, dir_path)

    # Load the module
    module_name = os.path.splitext(os.path.basename(file_path))[0]
    spec = importlib.util.spec_from_file_location(module_name, file_path)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)

    # Remove the directory from sys.path
    if dir_path in sys.path:
        sys.path.remove(dir_path)

    return unittest.defaultTestLoader.loadTestsFromModule(module)

def run_tests():
    # Get the current directory
    current_dir = os.path.dirname(os.path.abspath(__file__))
    
    # Create a test suite
    test_suite = unittest.TestSuite()
    
    # Walk through all subdirectories
    for root, dirs, files in os.walk(current_dir):
        for file in files:
            # Check if the file is a test file
            if file.startswith('test') and file.endswith('.py'):
                # Get the full path of the file
                file_path = os.path.join(root, file)
                
                # Load the tests from the file
                tests = load_tests_from_file(file_path)
                
                # Add the tests to the suite
                test_suite.addTest(tests)
    
    # Run the tests
    runner = unittest.TextTestRunner(verbosity=2)
    runner.run(test_suite)

if __name__ == '__main__':
    run_tests()