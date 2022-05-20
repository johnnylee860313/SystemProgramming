path = 'FileSharing.txt'
f = open(path,'w')

for i in range(101):
    f.write(str(i))
    f.write('\n')
f.close()