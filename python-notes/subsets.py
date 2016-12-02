# -*- coding: utf-8 -*-
'''
I. 문제를 풀 때, 직접적인 코드 참조를 하기 보다는 
아이디어와 논리적 추론, 그리고 결과 분석을 통하여.

Q. 1차원 자료구조의 모든 부분 집합을 구하는 문제 -> 멱집합

주안점 : 중복을 피할 것

아이디어 : 각 갈래의 결과물을 하나의 부분집합이 되도록 하고, 이것들을 합칠 것.

예외 : 현재 인덱스가 마지막인 경우, 기존 로직 대신 추가적 로직 수행
-> 마지막 조건문과 로직을 이어주는 징검다리, [ O -> A(추가된 로직) -> R ]
'''


def f(a,r=[]):
    if a == []:
        return [r]
    elif len(a) <= 1:
        return f([], r + [a[0]]) + f([], r)
    else:
        return f(a[1:], r + [a[0]]) + f(a[1:], r)


print(f([-1]))
print(f([1,2]))
print(f([1,2,3]))
print(f([1,2,3,4]))
assert len(f(list(range(10)))) == 2 ** 10
assert len(f(list(range(20)))) == 2 ** 20
