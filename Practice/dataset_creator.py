from csv import writer
from csv import reader
from csv import DictReader
from csv import DictWriter


def main():
    with open("/root/nishant/snap/large/eval_1.csv", 'r') as read_obj, open("/root/nishant/snap/large/eval.csv", 'a', newline='') as write_obj:
        csv_reader = reader(read_obj)
        csv_writer = writer(write_obj)
        for row in csv_reader:
            for j in range(1,14,1):
                for i in range(25):
                   row.insert(14,row[j])                     
            for k in range(1,5,1):
                row.insert(14,row[k])
            for l in range(343,365,1):
                    row.append(row[l])
            if(csv_reader.line_num < 10):     
                print("Row :",csv_reader.line_num," : ",row)
                print("No of column: ",len(row))
            else:
                if (csv_reader.line_num % 100000 == 0):
                    print(csv_reader.line_num, ":steps completed")

            csv_writer.writerow(row)



if __name__ == '__main__':
    main()
"""




        for row in csv_reader:
            #for j in range(1,14,1):
            #for j in range(1,5,1):
            for j in range(343,365,1):
                #for i in range(25):
                #for i in range(1):
                    row.append(row[j]) 
                    #row.insert(14,row[j])  
            #print(row[0],row[343],row[344],row[390])
            print(row)
            print("record number ",csv_reader.line_num)
            #print(row[0],row[1],row[338],row[339],row[342],row[343],row[390])
            print(len(row))
            csv_writer.writerow(row)
"""