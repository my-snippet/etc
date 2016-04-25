import ex


ex.prints(
    ex.evals(
        ex.inputs(
            ex.pred,
            ex.user_inputs,
            "1 <= N <= 10, Only sequence of numbers in 0-9 allowed"
        )
    )
)
