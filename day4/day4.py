def day4_part1(grid):
    if not grid:
        return 0
    row_count = len(grid)
    col_count = len(grid[0])
    neighbor_steps = [
        (-1, -1),
        (-1, 0),
        (-1, 1),
        (0, -1),
        (0, 1),
        (1, -1),
        (1, 0),
        (1, 1),
    ]
    answer = 0

    for row in range(row_count):
        for col in range(col_count):
            if grid[row][col] != "@":
                continue

            nearby_count = 0
            for row_change, col_change in neighbor_steps:
                next_row = row + row_change
                next_col = col + col_change
                if 0 <= next_row < row_count and 0 <= next_col < col_count:
                    if grid[next_row][next_col] == "@":
                        nearby_count += 1

            if nearby_count < 4:
                answer += 1

    return answer


def main():
    file = open("day4/input.txt")
    lines = file.readlines()
    file.close()

    grid = []
    for line in lines:
        grid.append(list(line.strip()))

    print(day4_part1(grid))


if __name__ == "__main__":
    main()
