from src import linear_regression, data_generator, ft_math


def test():
    tests = data_generator.generate_random_data(3)

    for test in tests:
        print('\nbegin test file {}.csv'.format(test['file']))
        result = linear_regression.run(test['file'], True)
        if ft_math.ft_abs(result[1] - test['result'][1]) / 100 > 0.1:
            print('___ failed ___')
            print(test, result)
        else:
            print('*** succes ***')
        print('end test file {}.csv'.format(test['file']))


test()
