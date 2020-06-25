from src import linear_regression, ft_math

def get_thetas(filename: str, mode: int) -> list:
    if mode & 1:
        linear_regression.run(filename, mode & 2)
    filename = './data/{}_prophecy.csv'.format(filename)
    try:
        thetas = open(filename, 'r').read()
    except FileNotFoundError:
        thetas = "0,0"

    return thetas.split(',')


def compute_price(distance: int, filename: str, mode: int):
    thetas = get_thetas(filename, mode)
    price = ft_math.linear(distance, thetas)
    print(
        'This car should cost {} euros.\
            \n\tHis kilometrage (distance) is {}\
            \n\tfunction used: price(distance) = {} + {} * distance'
        .format(
            int(price),
            distance,
            thetas[0],
            thetas[1]
        )
    )
