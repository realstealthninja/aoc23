import re  # only required module
from time import process_time  # used to time the execution

# using a positve look \/ ahead to overlap regex matches
digit = re.compile(r"(?=(one|two|three|four|five|six|seven|eight|nine|\d))")
# having a dictionary to convert values to singlular digits
words = {
    "zero": "0",
    "one": "1",
    "two": "2",
    "three": "3",
    "four": "4",
    "five": "5",
    "six": "6",
    "seven": "7",
    "eight": "8",
    "nine": "9",
}


# finds a calibration for a given string
def find_calibration(string: str) -> int:
    match = digit.findall(string)
    # comment this line for the first puzzle's answer
    match = list(map(lambda n: n if n not in words.keys() else words.get(n), match))
    return int(match[0] + match[len(match) - 1])


# to iterate over all calibrations and add the sum together
def find_all_calibration(calibrations: list) -> int:
    sum_of_values = 0
    for calibration in calibrations:
        sum_of_values += find_calibration(calibration)
    print(sum_of_values)


def main() -> None:
    calibrations = []
    with open("input.txt", "r") as f:
        for line in f:
            calibrations.append(line)
    start = process_time()
    find_all_calibration(calibrations)
    end = process_time()
    print(end - start)


if __name__ == "__main__":
    main()
