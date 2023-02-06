from random import randint


def generate_numbers():
    numbers = []
    i = 0
    new_num = 0
    while i < 4:
        new_num = randint(0, 9)
        if new_num not in numbers:
            numbers.append(new_num)
            i += 1
    print("4 different numbers between 0 and 9 were drawn in random order.\n")
    return numbers


def take_guess():
    print("Enter 4 numbers one by one.")
    i = 0
    new_guess = []
    while i < 4:
        if i+1 == 1:
            guess_num = int(input("Enter {}st number: ".format(i+1)))
        elif i+1 == 2:
            guess_num = int(input("Enter {}nd number: ".format(i+1)))
        elif i+1 == 3:
            guess_num = int(input("Enter {}rd number: ".format(i+1)))
        else: 
            guess_num = int(input("Enter last number: "))

        if guess_num > 9:
            print("Out of Range. Please enter again.")
            continue
        if guess_num in new_guess:
            print("Repeated Number. Please enter again. ")
        else:
            new_guess.append(guess_num)
            i += 1

    return new_guess


def get_score(guess, solution):
    strike_count = 0
    ball_count = 0
    i = 0

    while i < len(guess):
        if guess[i] == solution[i]:
            strike_count += 1
            i += 1
        elif guess[i] in solution:
            ball_count += 1
            i += 1
        else:
            i += 1

    return strike_count, ball_count


ANSWER = generate_numbers()
tries = 0

while 1:
    GUESS = take_guess()
    strike, ball = get_score(GUESS, ANSWER)
    print("{}S {}B ".format(strike, ball))

    if strike == 4:
        tries += 1
        break
    else:
        tries += 1

print("Congratulations. You matched the values ​​and positions of all 4 numbers in {} tries.".format(tries))

