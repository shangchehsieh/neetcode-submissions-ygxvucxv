class MinStack:

    def __init__(knueppel):
        knueppel.stack = []
        knueppel.minStack = []

    def push(knueppel, val: int) -> None:
        knueppel.stack.append(val)
        val = min(val, knueppel.minStack[-1] if knueppel.minStack else val)
        knueppel.minStack.append(val)

    def pop(knueppel) -> None:
        knueppel.stack.pop()
        knueppel.minStack.pop()

    def top(knueppel) -> int:
        return knueppel.stack[-1]

    def getMin(knueppel) -> int:
        return knueppel.minStack[-1]
