import matplotlib.pyplot as plt
from src.ft_math import linear, ft_pow


def partial_derivative_theta0(theta: list, data: list) -> float:
    return linear(data[0], theta) - data[1]


def partial_derivative_theta1(theta: list, data: list) -> float:
    return partial_derivative_theta0(theta, data) * data[0]


def gradient_descent(theta: float, data: list, ratio: float) -> float:
    tmp = [partial_derivative_theta0(theta, line) for line in data]
    tmp_theta0 = sum(tmp)
    tmp = [partial_derivative_theta1(theta, line) for line in data]
    tmp_theta1 = sum(tmp)

    return [theta[0] - ratio * tmp_theta0, theta[1] - ratio * tmp_theta1]


def cost_function(data: list, theta: list, count: int):
    return 1 / (2 * count) * sum([ft_pow(linear(item[0], theta) - item[1], 2) for item in data])


def plot_data_per_ratio(J_theta: list, ratio: str, j: int):
    i = 1
    plt.subplot(3, 2, j)
    plt.xlabel('iteration')
    plt.ylabel('cost function')
    legend = 'ratio = {}'.format(ratio)
    plt.title(legend)
    for item in J_theta:
        plt.plot(i, item, '.k', label=legend)
        i += 1


def compute_theta(data: list):
    # precision = 0.001 # just a possibility, test evolution of cost_function
    count_data = len(data)
    J_theta = []
    j = 1

    saved_theta = [0, 0]
    max_steps = 500 # 500 is just a value, could be 2000, 20000, for our kind of sets, should be good
    for ratio in [0.001, 0.003, 0.01, 0.03, 0.1, 0.3]:
        theta = [0, 0]
        i = 1
        J_theta = []
        delta = 0
        while (i < max_steps):
            J_theta.append(cost_function(data, theta, count_data))
            if i > 10:
                delta = J_theta[-1] - J_theta[-2]
                if delta == J_theta[-2] - J_theta[-3]:
                    print('convergence done for ratio {} in {} step'.format(ratio, i))
                    break
                if delta > 0.0001:
                    i = 100000000
                    break
            theta = gradient_descent(theta, data, ratio)
            i += 1
        if i < max_steps:
            max_steps = i
            saved_theta = theta
        plot_data_per_ratio(J_theta, str(ratio), int(j))
        j += 1

    return saved_theta
