class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        # row / col
        for i in range(9):#col
            row_check = []
            col_check = []
            for j in range(9):#row
                if board[i][j] != ".":
                    row_check.append(board[i][j])
                if board[j][i] != ".":
                    col_check.append(board[j][i])

            if len(row_check) != len(set(row_check)): return False
            if len(col_check) != len(set(col_check)): return False

        #squares
        for start in range(9):
            squ_check = []
            for i in range(3*(start//3), 3*(start//3)+3): #row
                for j in range(3*(start%3), 3*(start%3)+3): #col
                    if board[i][j] != ".":
                        squ_check.append(board[i][j])
            if len(squ_check) != len(set(squ_check)): return False
        #00 03 06 30 33 36 60 63 66
        return True