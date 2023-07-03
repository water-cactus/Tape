import sys
import subprocess
from pathlib import Path


if __name__ == '__main__':
    '''
    sys.argv[1] - dir with tests
    '''
    dir_tests = Path(sys.argv[1])

    for file_test in dir_tests.iterdir():
        if file_test.name.startswith('input_'):

            with open(file_test, 'r') as input_file:
                data_py = sorted([int(x) for x in input_file.read().split()])

            status_sort_cpp = subprocess.call(['./a.out', file_test, 'tests/output_cpp.txt'])

            with open('tests/output_cpp.txt', 'r') as output_cpp:
                data_cpp = [int(x) for x in output_cpp.read().split()]

            if data_py == data_cpp:
                print('Test passed')
            else:
                print(data_py)
                print(data_cpp)
                print('Test failed:', file_test.name)
