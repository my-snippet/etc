coins = [2, 5, 3, 6]


def count_num_coins(coins, amount, result=[0]):

    def iter(_amount, _coins, _num_coins, stack=[]):
        if _amount == 0:
            result[0] += 1
            print(stack)
        elif _amount < 0 or _num_coins == 0:
            pass
        else:
            iter(_amount, _coins[1:], _num_coins-1, stack)
            iter(_amount - _coins[0], _coins, _num_coins, stack + [_coins[0]])

    iter(amount, coins, len(coins))
    return result[0]

print(count_num_coins(coins, 100))
