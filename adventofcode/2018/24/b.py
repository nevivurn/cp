#!/usr/bin/env python3

import re
from itertools import chain
import operator

immune = """2785 units each with 4474 hit points (weak to cold) with an attack that does 14 fire damage at initiative 20
4674 units each with 7617 hit points (immune to slashing, bludgeoning; weak to fire) with an attack that does 15 slashing damage at initiative 15
1242 units each with 1934 hit points (weak to fire) with an attack that does 15 bludgeoning damage at initiative 6
1851 units each with 9504 hit points (weak to bludgeoning) with an attack that does 47 slashing damage at initiative 2
846 units each with 9124 hit points (weak to bludgeoning; immune to radiation) with an attack that does 99 bludgeoning damage at initiative 4
338 units each with 1378 hit points (immune to radiation) with an attack that does 39 cold damage at initiative 10
3308 units each with 5087 hit points (weak to radiation) with an attack that does 12 fire damage at initiative 3
2668 units each with 8316 hit points (weak to bludgeoning, radiation) with an attack that does 28 slashing damage at initiative 9
809 units each with 1756 hit points (immune to bludgeoning) with an attack that does 21 cold damage at initiative 1
4190 units each with 8086 hit points (immune to cold) with an attack that does 18 cold damage at initiative 5"""

infection = """2702 units each with 10159 hit points with an attack that does 7 fire damage at initiative 7
73 units each with 14036 hit points (weak to fire) with an attack that does 384 radiation damage at initiative 18
4353 units each with 35187 hit points with an attack that does 15 slashing damage at initiative 14
370 units each with 9506 hit points (weak to bludgeoning, radiation) with an attack that does 46 slashing damage at initiative 12
4002 units each with 22582 hit points (weak to radiation, cold) with an attack that does 11 fire damage at initiative 8
1986 units each with 24120 hit points (immune to fire) with an attack that does 22 radiation damage at initiative 11
1054 units each with 17806 hit points with an attack that does 25 cold damage at initiative 16
124 units each with 37637 hit points with an attack that does 589 cold damage at initiative 19
869 units each with 11019 hit points (weak to fire) with an attack that does 24 cold damage at initiative 17
3840 units each with 38666 hit points (immune to slashing, fire, bludgeoning) with an attack that does 19 bludgeoning damage at initiative 13"""

#immune = """17 units each with 5390 hit points (weak to radiation, bludgeoning) with an attack that does 4507 fire damage at initiative 2
#989 units each with 1274 hit points (immune to fire; weak to bludgeoning, slashing) with an attack that does 25 slashing damage at initiative 3"""
#
#infection = """801 units each with 4706 hit points (weak to radiation) with an attack that does 116 bludgeoning damage at initiative 1
#4485 units each with 2961 hit points (immune to radiation; weak to fire, cold) with an attack that does 12 slashing damage at initiative 4"""

class Group:
    def __init__(self, units, hp, details, dmg, dmg_type, initiative):
        self.units = int(units)
        self.hp = int(hp)
        self.details = details
        self.dmg = int(dmg)
        self.dmg_type = dmg_type
        self.initiative = int(initiative)

        self.immune = []
        self.weak = []
        if details:
            for detail in details.split('; '):
                dtype = detail.split()[0]
                dets = detail.split(', ')
                dets[0] = dets[0].split()[-1]

                if dtype == 'immune':
                    self.immune = dets
                elif dtype == 'weak':
                    self.weak = dets

    def copy(self):
        return Group(self.units, self.hp, self.details, self.dmg, self.dmg_type, self.initiative)

    def power(self):
        return self.units * self.dmg

    def dmg_to(self, other):
        dmg = self.power()
        if self.dmg_type in other.weak:
            dmg *= 2;
        elif self.dmg_type in other.immune:
            dmg = 0
        return dmg

    def __str__(self):
        return str(self.__dict__)

def parse_group(line):
    m = re.match(r'(\d+) units each with (\d+) hit points(?: \((.*)\))? with an attack that does (\d+) (\w+) damage at initiative (\d+)', line)
    return Group(*m.groups())

def battle(orig_infection, orig_immune, boost):
    infection = []
    immune = []

    for g in orig_infection:
        infection.append(g.copy())
    for g in orig_immune:
        g = g.copy()
        g.dmg += boost
        immune.append(g)

    while len(infection) > 0 and len(immune) > 0:
        # Target selection
        targeted = []
        for grp in sorted(chain(immune, infection), key=lambda g: (g.power(), g.initiative), reverse=True):
            if grp in infection:
                target = immune
            elif grp in immune:
                target = infection

            other = max((oth for oth in target if oth not in targeted), key=lambda oth: (grp.dmg_to(oth), oth.power(), oth.initiative), default=None)
            if other != None and grp.dmg_to(other) != 0:
                targeted.append(other)
                grp.target = other
            else:
                grp.target = None

        # Damage
        killed = False
        for grp in sorted(chain(immune, infection), key=lambda g: g.initiative, reverse=True):
            if grp.target == None:
                continue

            target = grp.target

            dmg = grp.dmg_to(target)
            units = dmg // target.hp
            if units > 0:
                killed = True
            target.units -= min(target.units, units)

        if not killed:
            return -1

        immune = [grp for grp in immune if grp.units > 0]
        infection = [grp for grp in infection if grp.units > 0]

    if len(immune) == 0:
        return -1
    return sum(g.units for g in immune)

orig_immune = list(map(parse_group, immune.splitlines()))
orig_infection = list(map(parse_group, infection.splitlines()))

boost = 0
while True:
    ans = battle(orig_infection, orig_immune, boost)
    if ans > 0:
        print(ans)
        break
    boost += 1
