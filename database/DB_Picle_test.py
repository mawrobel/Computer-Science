from initdata import db
import pickle

dbfile = open('people-pickle', 'wb')
pickle.dump(db, dbfile)
dbfile.close()

dbfile = open('people-pickle', 'rb')
db = pickle.load(dbfile)
for key in db:
    print(key, "=>\n", db[key])
dbfile.close()
