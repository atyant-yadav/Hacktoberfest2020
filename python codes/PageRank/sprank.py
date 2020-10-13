import sqlite3

conn = sqlite3.connect('spider.sqlite')
cur=conn.cursor()

from_ids=list()
cur.execute('SELECT DISTINCT from_id FROM Links')
for row in cur:
    from_ids.append(row[0])

to_ids=list()
links=list()
cur.execute('SELECT from_id, to_id FROM Links')
for row in cur:
    from_id=row[0]
    to_id=row[1]
    if from_id not in from_ids: continue
    if to_id not in to_ids: to_ids.append(to_id)
    if from_id == to_id:continue
    if to_id not in from_ids:continue
    links.append(row)


prev_ranks=dict()
for node in from_ids:
    cur.execute('SELECT new_rank FROM Pages WHERE id=?',(node,))
    row = cur.fetchone()
    prev_ranks[node]=row[0]

if len(prev_ranks) < 1 :
    print("Nothing to page rank.  Check data.")
    quit()

many=1
sval=input('How many interations: ')
if len(sval)>0 : many = int(sval)

for i in range(many):
    next_ranks = dict()
    total=0.0
    for (node,old_rank) in list(prev_ranks.items()):
        total=total+old_rank
        next_ranks[node]=0.0


    for (node, old_ranks) in list(prev_ranks.items()):
        give_ids=list()
        for (from_id,to_id) in links:
            if from_id!=node : continue
            if to_id not in to_ids: continue
            give_ids.append(to_id)

        if len(give_ids)<1 : continue
        amount=old_rank/len(give_ids)

        for id in give_ids:
            next_ranks[id]=next_ranks[id]+amount


    newtot=0
    for (node, next_rank) in list(next_ranks.items()):
        newtot = newtot + next_rank
    evap = (total - newtot) / len(next_ranks)

    # print newtot, evap
    for node in next_ranks:
        next_ranks[node] = next_ranks[node] + evap

    newtot = 0
    for (node, next_rank) in list(next_ranks.items()):
        newtot = newtot + next_rank

    # Compute the per-page average change from old rank to new rank
    # As indication of convergence of the algorithm
    totdiff = 0
    for (node, old_rank) in list(prev_ranks.items()):
        new_rank = next_ranks[node]
        diff = abs(old_rank-new_rank)
        totdiff = totdiff + diff

    avediff = totdiff / len(prev_ranks)
    print(i+1, avediff)

    # rotate
    prev_ranks = next_ranks

print(list(next_ranks.items())[:5])
cur.execute('''UPDATE Pages SET old_rank=new_rank''')
for (id, new_rank) in list(next_ranks.items()) :
    cur.execute('''UPDATE Pages SET new_rank=? WHERE id=?''', (new_rank, id))
conn.commit()
