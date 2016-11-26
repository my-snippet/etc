def mul(mc, mf, result=0):
    if mc:
        if mc % 2:
            return mul(mc//2, mf<<1, result+mf)
        else:
            return mul(mc//2, mf<<1, result)
    else:
        return result
