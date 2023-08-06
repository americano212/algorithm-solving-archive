score_save = []
for i in range(1, 21):
    problem = 525 + i
    score = 175 * (1 - 0.995**problem)
    score_before = 175 * (1 - 0.995**(problem - 1))
    if (int(score) != int(score_before)):
        print('*'*50)
    print("{}문제 후".format(i), score)
