#!/usr/bin/env python3

import sys
from collections import namedtuple

Point = namedtuple('Point', ['x', 'y'])
Unit = namedtuple('Unit', ['id', 'hp', 'atk', 'race', 'x', 'y'])

directions = [Point(1, 0), Point(0, 1), Point(-1, 0), Point(0, -1)]

def dist(a, b):
    return abs(a.x - b.x) + abs(a.y - b.y)
def addp(a, b):
    return Point(a.x+b.x, a.y+b.y)

grid = [list(line.strip()) for line in sys.stdin]

def passable(p):
    if 0 <= p.x < len(grid[0]) and 0 <= p.y < len(grid):
        return grid[p.y][p.x]
    return False

units = []
for y, line in enumerate(grid):
    for x, c in enumerate(grid[y]):
        if c == 'E' or c == 'G':
            units.append(Unit(len(units), 200, 3, c, x, y))
        grid[y][x] = c != '#' # true if passable

cnt = 0
while True:
    # get round ordering
    order = sorted(range(len(units)), key=lambda uid: (units[uid].y, units[uid].x))
    # current mid-round state of units

    for uid in order:
        unit = units[uid]
        if unit.hp <= 0:
            continue

        curpos = Point(unit.x, unit.y)

        # search for targets
        targets = [u for u in units if u.race != unit.race and u.hp > 0]

        # end combat if no targets
        if len(targets) == 0:
            break

        # check if in range, otherwise move
        if not any(dist(t, unit) == 1 for t in targets):
            # squares occupied by another unit
            occupied = {Point(u.x, u.y) for u in units if u.hp > 0}

            # enumerate in-range squares
            inrange = {addp(Point(t.x, t.y), d) for t in targets for d in directions}
            inrange = {p for p in (addp(Point(t.x, t.y), d) for t in targets for d in directions) if p not in occupied and passable(p)}

            # end turn if no squares in range
            if len(inrange) == 0:
                continue

            # find nearest in-range square
            initstep = {s for s in (addp(curpos, d) for d in directions) if s not in occupied and passable(s)}
            curstep = initstep.copy()
            seen = initstep.copy()
            while len(curstep & inrange) == 0 and len(curstep) > 0:
                nextstep = {s for s in (addp(s, d) for s in curstep for d in directions) if s not in seen and s not in occupied and passable(s)}
                seen |= nextstep
                curstep = nextstep

            # determine destination square
            if len(curstep & inrange) == 0:
                continue
            dest = min((s for s in curstep & inrange), key=lambda s: (s.y, s.x))

            # pathfind
            if dest not in initstep:
                curstep = {s for s in (addp(dest, d) for d in directions) if s not in occupied and passable(s)}
                seen = curstep.copy()
                while len(curstep & initstep) == 0:
                    nextstep = {s for s in (addp(s, d) for s in curstep for d in directions) if s not in seen and s not in occupied and passable(s)}
                    seen |= nextstep
                    curstep = nextstep
                # determine immediate step this unit takes
                onestep = min((s for s in curstep & initstep), key=lambda s: (s.y, s.x))
            else:
                onestep = dest

            # update units
            unit = Unit(unit.id, unit.hp, unit.atk, unit.race, onestep.x, onestep.y)
            units[uid] = unit

        # select attack target
        target = min((u for u in targets if dist(u, unit) == 1), key=lambda u: (u.hp, u.y, u.x), default=None)
        if target == None:
            continue

        # update units
        target = Unit(target.id, target.hp - unit.atk, target.atk, target.race, target.x, target.y)
        units[target.id] = target
    else:
        cnt += 1
        continue
    break

remhp = sum(u.hp for u in units if u.hp > 0)
print(remhp * cnt)
