import pytest
from pysrc.recursion import factorial


def test_factorial_with_invalid_input():
    with pytest.raises(AssertionError) as e:
        factorial(0)

def test_factorial_with_valid_input():
    assert(factorial(5) == 120)