def solve_maze(maze):
    def dfs(x, y, path):
        if not (0 <= x < len(maze) and 0 <= y < len(maze[0])) or maze[x][y] == "*":
            return False
        if maze[x][y] == "T":
            return True
        path.append((x, y))
        maze[x][y] = "*"
        if dfs(x+1, y, path) or dfs(x-1, y, path) or dfs(x, y+1, path) or dfs(x, y-1, path):
            return True
        path.pop()
        return False 
    rows = len(maze)
    cols = len(maze[0])
    start = (0, 0)
    end = (0, 0)
    for i in range(rows):
        for j in range(cols):
            if maze[i][j] == 'P':
                start = (i, j)
            elif maze[i][j] == 'T':
                end = (i, j)        
    path = []
    if dfs(start[0], start[1], path):
        return "Solved", path
    else:
        return "Unsolved", []
maze1 = [
    [" ", "*", " ", "*", " ", " "],
    [" ", "*", " ", "*", " ", " "],
    ["P", " ", " ", " ", "*", " "],
    ["*", " ", "*", "*", "*", " "],
    [" ", " ", " ", " ", "*", "T"],
    ["*", " ", " ", " ", " ", " "]
]
status, path = solve_maze(maze1)
print(status)
if status == "Solved":
    print("Path:", path)
maze2 = [
    [" ", "*", " ", "*", " ", " "],
    [" ", "*", " ", "*", " ", " "],
    ["P", " ", " ", " ", "*", " "],
    ["*", " ", "*", "*", "*", " "],
    [" ", " ", " ", " ", "*", "T"],
    ["*", " ", " ", " ", " ", "*"]
]
status, path = solve_maze(maze2)
print(status)
if status == "Solved":
    print("Path:", path)
