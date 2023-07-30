for i in range(20):
    problem = 515 + i
    score = 175 * (1 - 0.995**problem)
    print("{}문제 후".format(i), score)
