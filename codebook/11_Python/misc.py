from decimal import *
setcontext(Context(prec=MAX_PREC, Emax=MAX_EMAX, rounding=ROUND_FLOOR))
print(Decimal(input()) * Decimal(input()))
from fractions import Fraction
Fraction('3.14159').limit_denominator(10).numerator # 22
sys.set_int_max_str_digits(int(1e6))
a, b = map(int, input().split())
a = map(int, input().split())  # array