import pymysql
import fileinput
import book_and_cancel
import log_in


#输入
def main():
    print("please log_in")
    user_name=log_in.log_in()
    #??pydev debugger: process 8328 is connecting

    #选择界面循环
    choice=1
    while choice!=0:
        print("function:3.view 4.select 5.find 6.book_ticket 7.cancel_ticket")
        # _input=input()
        _input=6
        if(_input==3):
            return
        if(_input==4):
            return
        if(_input==5):
            break # find()
        if(_input==6):
            book_and_cancel.book_ticket(user_name)
        if(_input==7):
            book_and_cancel.cancel_ticket()
        #提示是否跳出选择界面循环
        print("want to exit,enter make choice ==0 else enter 1 to continue")
        choice = input()
        if(choice==1):
            continue
        else:
            break




    
main()

