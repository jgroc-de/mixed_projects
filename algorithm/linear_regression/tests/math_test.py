from src.ft_math import linear, ft_pow, ft_abs
from src.ft_gradient_descent import partial_derivative_theta0, partial_derivative_theta1, gradient_descent


def test():
    linear_test = [
        [[1, 0], 2, 1],
        [[1, 0], 1, 1],
        [[1, 0], 0, 1],
        [[1, 0], -1, 1],
        [[-2, 0], -1, -2],

        [[0, 1], 2, 2],
        [[0, 1], 1, 1],
        [[0, 1], 0, 0],
        [[0, 1], -1, -1],
        [[0, -2], 2, -4],

        [[1, 1], 1, 2],
        [[-1, -1], 1, -2],
        [[-1, 1], 1, 0],
        [[-2, 3], 1, 1],
    ]

    for item in linear_test:
        result = linear(item[1], item[0])
        if (result != item[2]):
            print(item, result)
            break

    partial_derivative_theta_test = [
        # theta = 0
        [[0, 0], [1, 1], -1, -1],
        [[0, 0], [2, 0], 0, 0],
        [[0, 0], [0, 2], -2, 0],
        # theta1 = 0
        [[1, 0], [1, 1], 0, 0],
        [[1, 0], [0, 2], -1, 0],
        [[1, 0], [2, 0], 1, 2],
        # theta0 = 0
        [[0, 1], [2, 2], 0, 0],
        [[0, 1], [2, 0], 2, 4],
        [[0, 1], [0, 2], -2, 0],
        # theta != 0
        [[2, 2], [1, 1], 3, 3],
        [[2, 2], [0, 2], 0, 0],
        [[2, 2], [2, 0], 6, 12],
        # with neg numbers
        [[-2, 2], [2, 0], 2, 4],
        [[-2, 2], [2, 1], 1, 2],
        [[-2, 2], [2, -3], 5, 10],
        [[-2, 2], [-2, 1], -7, 14],
    ]

    for item in partial_derivative_theta_test:
        result0 = partial_derivative_theta0(item[0], item[1])
        result1 = partial_derivative_theta1(item[0], item[1])
        if (result0 != item[2] or result1 != item[3]):
            print(item, result0, result1)
            break

    gradient_descent_test = [
        [[0, 0], [[0, 0], [1, 1]], [1, 1]],
        [[1, 1], [[0, 0], [1, 1]], [-1, 0]],
        [[0, -1], [[0, 0], [1, 1]], [2, 1]],
        [[-1, -1], [[0, 0], [1, 1]], [3, 2]],
        [[0, 1], [[0, 0], [1, 1]], [0, 1]],
    ]
    ratio = 2
    for item in gradient_descent_test:
        result = gradient_descent(item[0], item[1], ratio / len(item[1]))
        if (result != item[2]):
            print(item, result)
            break

    gradient_descent_test = [
        [[0, 0], [[0, 0], [1, 1]], [0.5, 0.5]],
        [[1, 1], [[0, 0], [1, 1]], [0, 0.5]],
        [[0, -1], [[0, 0], [1, 1]], [1, 0]],
        [[-1, -1], [[0, 0], [1, 1]], [1, 0.5]],
        [[0, 1], [[0, 0], [1, 1]], [0, 1]],
    ]
    ratio = 1
    for item in gradient_descent_test:
        result = gradient_descent(item[0], item[1], ratio / len(item[1]))
        if (result != item[2]):
            print(item, result)
            break

    pow_test = [
        [1, 2, 1],
        [0, 2, 0],
        [0, 0, 1],
        [42, 0, 1],
        [42, -1, 1 / 42],
        [10, 2, 100],
        [10, 3, 1000],
        [2, 2, 4],
        [2, 10, 1024],
        [0.5, 2, 0.25],
    ]
    for item in pow_test:
        result = ft_pow(item[0], item[1])
        if (result != item[2]):
            print(item, result)
            break

    abs_test = [
        [1, 1],
        [0, 0],
        [-1, -1],
        [-0.5, -0.5],
    ]
    for item in abs_test:
        result = ft_abs(item[0])
        if (result != item[1]):
            print(item, result)
            break


test()
