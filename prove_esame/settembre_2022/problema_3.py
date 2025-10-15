from math import *

def f(x,p,q,r,s,t,u):
    return p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x**2 + u

def solve(lo,hi,p,q,r,s,t,u,roots:list,eps=1e-1):
    f_lo = f(lo, p, q, r, s, t, u)
    f_hi = f(hi, p, q, r, s, t, u)

    if abs(f_lo) <= 1e-20:
        if lo not in roots:
            roots.append(lo)
    if abs(f_hi) <= 1e-20:
        if hi not in roots:
            roots.append(hi)
    if hi-lo <= eps:
        return 

    mid = (lo+hi)/2
    f_mid = f(mid, p, q, r, s, t, u)
    if f_mid <= 1e-20:
        if mid not in roots:
            roots.append(mid)
    
    solve(lo, mid, p, q, r, s, t, u, roots)
    solve(mid, hi, p, q, r, s, t, u, roots)

def solve_single(lo, hi, p, q, r, s, t, u):
    f_lo = f(lo, p, q, r, s, t, u)
    f_hi = f(hi, p, q, r, s, t, u)

    if abs(f_lo) <= 1e-5: 
        return lo
    if abs(f_hi) <= 1e-5:
        return hi 
    
    if f_lo*f_hi > 0 or hi-lo < 1e-9:
        return None

    mid = (lo+hi)/2
    f_mid = f(mid, p, q, r, s, t, u)

    if f_lo * f_mid > 0:
        return solve_single(mid, hi, p, q, r, s, t, u)
    else:
        return solve_single(lo, mid, p, q, r, s, t, u)
    
if __name__ == '__main__':
    root = solve_single(0.0, 1.0, 1, 0, 0, 0, -1, 2)
    if root != None:
        print(f"{root:.4f}")
    else:
        print('Nessuna soluzione')
