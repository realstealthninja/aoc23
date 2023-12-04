def part_one(line: str) -> int:
    point = 0
    win_and_given = line.split(":")[1].replace("\n", "").split("|")
    given = [int(i) for i in win_and_given[1].split(" ") if i]
    win = [int(i) for i in win_and_given[0].split(" ") if i]
    for num in given:
        if num in win:
            if point == 0:
                point = 1
            else:
                point += point
    return point


def part_two(lines: list) -> int:
    cards = {card: 1 for card in range(1, len(lines) + 1)}
    for line in lines:
        win_and_given = line.split(":")[1].replace("\n", "").split("|")
        given = [int(i) for i in win_and_given[1].split(" ") if i]
        win = [int(i) for i in win_and_given[0].split(" ") if i]
        card_number = int(line.split(":")[0][4:].strip())
        matches = len([i for i in given if i in win])
        for i in range(card_number + 1, card_number + 1 + matches):
            cards[i] += cards[card_number]

    return sum(cards.values())


def main():
    sum = 0
    with open("input.txt", "r") as file:
        for line in file:
            sum += part_one(line)
    print(sum)
    # part 2

    with open("input.txt", "r") as file:
        lines = []
        for line in file:
            lines.append(line)
        print(part_two(lines))


if __name__ == "__main__":
    main()
