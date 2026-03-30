class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        col = defaultdict(set) #key: c
        row = defaultdict(set) #key: r
        squ = defaultdict(set) #key: (r//3, c//3) (tuple)

        for r in range(9):
            for c in range(9):
                if board[r][c] == ".":
                    continue
                if (board[r][c] in col[c] 
                or board[r][c] in row[r] 
                or board[r][c] in squ[(r//3, c//3)]):
                    return False

                col[c].add(board[r][c]) #update 1-9 in cols
                row[r].add(board[r][c]) #update 1-9 in rows
                squ[(r//3, c//3)].add(board[r][c]) #update 1-9 in squares

        return True