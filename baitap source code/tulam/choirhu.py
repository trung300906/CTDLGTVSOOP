import random

class Row:
    def __init__(self, cols, is_odd):
        self.values = [0] * cols
        self.is_odd = is_odd

def check(store, hang):
    return any(val == 1 for val in store[hang].values)

def tim(store, loc, hang):
    for run in range(len(store[hang].values)):
        if store[hang].values[run] == 1:
            loc.append(run)

def tim_loc_2(store, loc, hang, loccur, dem):
    if not store[hang].is_odd:
        for i in range(loccur, S):
            if store[hang].values[i] == 1:
                loc.append(i)
    else:
        for i in range(loccur, -1, -1):
            if store[hang].values[i] == 1:
                loc.append(i)

    if loc:
        dem[0] += abs(loccur - loc[-1]) + 1
        loccur = loc[-1]

    return loccur

def main():
    random.seed()

    R, S = map(int, input().split())
    store = []

    for i in range(R):
        is_odd = ((R - 1) & 1) == 1 if (i & 1) == 1 else not (i & 1) == 1
        store.append(Row(S, is_odd))

        for j in range(S):
            if i == 0 and j == 0:
                store[i].values[j] = 2
            else:
                store[i].values[j] = random.randint(0, 1)

    loc = []
    dem = [0]  # Using a list to pass by reference
    loccur = 0

    for hang in range(R - 1, -1, -1):
        loc.clear()

        if not check(store, hang):
            if hang > 0:
                dem[0] += 1
                store[hang - 1].values[loccur] = 0
            continue

        tim(store, loc, hang)

        for i in loc:
            store[hang].values[i] = 0

        if store[hang].is_odd:
            dem[0] += abs(loccur - loc[-1]) + 1
            loccur = loc[-1]
            loc.clear()

            if hang > 0:
                loccur = tim_loc_2(store, loc, hang - 1, loccur, dem)
                store[hang - 1].values[loccur] = 0
                loc.clear()
        else:
            dem[0] += abs(loccur - loc[0]) + 1
            loccur = loc[0]
            loc.clear()

            if hang > 0:
                loccur = tim_loc_2(store, loc, hang - 1, loccur, dem)
                store[hang - 1].values[loccur] = 0
                loc.clear()

    print(dem[0])

if __name__ == "__main__":
    main()
