from tkinter import *
from tkinter import ttk
import tkinter.messagebox
from functools import partial
from turtle import bgcolor
import pyttsx3



root=Tk()
root.title("Unit Converter")
root.geometry("600x800")


#creating Tabs
my_notebook = ttk.Notebook(root)
my_notebook.pack(pady=5)



#Creating  Frames
main_frame= Frame(my_notebook,width = 1000,height = 1000,bg='black')
currency_frame= Frame(my_notebook,width = 1000,height = 1000,bg='black')
temperature_frame= Frame(my_notebook,width = 1000,height = 1000,bg='black')

main_frame.pack(fill='both',expand=1)
currency_frame.pack(fill='both',expand=1)
temperature_frame.pack(fill='both',expand=1)

my_notebook.add(main_frame,text ='Home')
my_notebook.add(currency_frame,text='Currency Conversion')
my_notebook.add(temperature_frame,text='Temperature Conversion')


# Disabling 1st and 2nd  Tab
my_notebook.tab(1,state='disabled')
my_notebook.tab(2,state='disabled')

def Temp():
     my_notebook.tab(2,state='normal')
     my_notebook.tab(1,state='disabled')
     my_notebook.tab(0,state='disabled')
def Currency():
    my_notebook.tab(1,state='normal')
    my_notebook.tab(2,state='disabled')  
    my_notebook.tab(0,state='disabled')
def Home():
    my_notebook.tab(0,state='normal')
    my_notebook.tab(1,state='disabled')
    my_notebook.tab(2,state='disabled')


home = Label(main_frame,text="Welcome to Unit Converter\n Select any of the below to start your Conversion",font="comicsense",bg="silver",fg='black',relief=GROOVE,borderwidth=10)
home.pack(pady=20)

#photo=ImageTk.PhotoImage(Image.open("preview.jpg"))
#panel1 = Label(main_frame,image=photo,height=150,width=150,relief=GROOVE,borderwidth=5)
#panel1.pack(padx=50,pady=50)

Currency_button = Button(main_frame,text="Currency Conversion",command=Currency,bg="black",fg="light blue",relief=SUNKEN,borderwidth=10)
Currency_button.pack(pady=5,padx=5)

#photo1=ImageTk.PhotoImage(Image.open("temp1.jpg"))
#panel2 = Label(main_frame,image=photo1,height=150,width=150,relief=GROOVE,borderwidth=5)
#panel2.pack(padx=50,pady=50)

Temp_button = Button(main_frame,text="Temperature Conversion",command=Temp,bg="black",fg="light blue",relief=SUNKEN,borderwidth=10)
Temp_button.pack(pady=5,padx=5)


engine1 = pyttsx3.init()
voices = engine1.getProperty('voices')
engine1.setProperty('voice', voices[1].id)
engine1.setProperty('rate', 150)
engine1.say("Good Afternoon, Welcome to the Unit Converter")
engine1.runAndWait()


engine2= pyttsx3.init()
engine2.say("Thank You")


#Currency Variables
variable1 = StringVar(currency_frame)
variable2 = StringVar(currency_frame)

#Temperature Variables
numberInput = StringVar(temperature_frame)
var = StringVar(temperature_frame)


#Currency Stuff and Program
variable1.set("Currency")
variable2.set("Currency")


def RealTimeCurrencyConversion():
    from forex_python.converter import CurrencyRates
    c = CurrencyRates()

    from_currency = variable1.get()
    to_currency = variable2.get()
    
    if  (Amount1_field.get()!=""):
        M=['1','2','3','4','5','6','7','8','9','0','.',' ']
        for i in Amount1_field.get():
            if i not in M:
                tkinter.messagebox.showerror("Error !!", " Please Enter numeric value.")
                break
    if True:
        count=0
        for i in Amount1_field.get():
            if i=='.':
                count+=1
        if count>1:
            tkinter.messagebox.showerror("Error !!", " Please Enter only one decimal point.") 
    if (Amount1_field.get() == ""):
        tkinter.messagebox.showerror("Error !!", "Amount Not Entered.\n Please a valid amount.")

    elif (from_currency == "Currency" or to_currency == "Currency"):
        tkinter.messagebox.showerror("Error !!","Currency Not Selected.\n Please select FROM and TO Currency from menu.")

    else:
        new_amt = c.convert(from_currency, to_currency, float(Amount1_field.get()))
        new_amount = float("{:.4f}".format(new_amt))
        Amount2_field.insert(0, str(new_amount))


def clear_all():
    Amount1_field.delete(0, END)
    Amount2_field.delete(0, END)

CurrenyCode_list = ["INR", "USD", "CAD","DKK", "EUR","IDR","BGN","ILS","GBP","JPY","AUD","HUF","RON","MYR","SGD","HKD","CHF","KRW","CNY","TRY","MXN","BRL"]


label1 = Label(currency_frame, font=('Helvetica', 12), text="\t    Amount  :  ", bg="black", fg="light blue")
label1.grid(row=2, column=0, sticky=W,pady=20)

label1 = Label(currency_frame, font=('Helvetica', 12), text="\t    From Currency  :  ", bg="black", fg="light blue")
label1.grid(row=3, column=0, sticky=W)

label1 = Label(currency_frame, font=('Helvetica', 12), text="\t    To Currency  :  ", bg="black", fg="light blue")
label1.grid(row=4, column=0, sticky=W)

label1 = Label(currency_frame, font=('Helvetica', 12), text="\t    Converted Amount  :  ", bg="black", fg="light blue")
label1.grid(row=8, column=0, sticky=W)

Label_1 = Label(currency_frame, font=('Helvetica', 10), text="", padx=2, pady=2, bg="black", fg="light blue")
Label_1.grid(row=5, column=0, sticky=W)

Label_1 = Label(currency_frame, font=('Helvetica', 10), text="", padx=2, pady=2, bg="black", fg="light blue")
Label_1.grid(row=7, column=0, sticky=W)

#creating Opyion Menu
FromCurrency_option = OptionMenu(currency_frame, variable1, *CurrenyCode_list)
ToCurrency_option = OptionMenu(currency_frame, variable2, *CurrenyCode_list)
FromCurrency_option.config(bg="black",fg="light blue",font=("Ariel",12))
ToCurrency_option.config(bg="black",fg="light blue",font=("Ariel",12))

FromCurrency_option.grid(row=3, column=5, ipadx=45, sticky=E)
ToCurrency_option.grid(row=4, column=5, ipadx=45, sticky=E)


#Amount Entry
Amount1_field = Entry(currency_frame)
Amount1_field.config(font=("Ariel",12))
Amount1_field.grid(row=2, column=5, ipadx=28, sticky=E,pady=10)

#Result Entry
Amount2_field = Entry(currency_frame)
Amount2_field.config(font=("Ariel",12))
Amount2_field.grid(row=8, column=5, ipadx=31, sticky=E)

Label_2 = Button(currency_frame, font=('arial', 12), text="   Convert  ", padx=2, pady=2, bg="black", fg="white",command=RealTimeCurrencyConversion,relief=RAISED,borderwidth=5)
Label_2.grid(row=6, column=5)

Label_1 = Label(currency_frame, font=('Helvetica', 7), text="", padx=2, pady=2, bg="black", fg="light blue")
Label_1.grid(row=9, column=5, sticky=W)

Label_2 = Button(currency_frame, font=('arial', 12), text="   Clear All  ", padx=2, pady=2, bg="black", fg="light blue",command=clear_all,relief=RAISED,borderwidth=5)
Label_2.grid(row=10, column=5)

currencytemp_button=Button(currency_frame,font=('arial', 12), text="   Temperature conversion  ", padx=2, pady=2, bg="black", fg="light blue",command=Temp,relief=RAISED,borderwidth=5)
currencytemp_button.grid(row=17 , column=5 ,sticky=E)

Home_button=Button(currency_frame,font=('arial', 12), text="   Back to Home  ", padx=2, pady=2, bg="black", fg="light blue",command=Home,relief=RAISED,borderwidth=5)
Home_button.grid(row=15,sticky=W)


#photo2=ImageTk.PhotoImage(Image.open("currencycodes.jpg"))
#panel3 = Label(currency_frame,image=photo2,height=150,width=150,relief=GROOVE,borderwidth=5)
#panel3.grid(ipadx=130,ipady=25,columnspan=10,padx=95,pady=30)

#------------------------------------------------------------------------------------------------------------------------------------------------

#Temperature Program
input_label = Label(temperature_frame, text="Enter Temperature",font=("comicsense",15),relief=RAISED,borderwidth=8 )
input_entry = Entry(temperature_frame, textvariable=numberInput,font=("Helvetica",14))
input_label.pack(padx=200,pady=50)
input_entry.pack(pady=10)

# getting drop down value
def store_temp(par_temp):
    global tempVal
    tempVal = par_temp

# drop down initalization and setup
dropDownList = ["Celsius", "Fahrenheit", "Kelvin"]
dropdown = OptionMenu(temperature_frame, var, *dropDownList, command=store_temp)
var.set("Unit")
dropdown.pack(padx=10,pady=10)
dropdown.config(foreground="light blue",bg="black",relief=RAISED,font=("Ariel",12))
dropdown["menu"].config( foreground="light blue",bg="black",borderwidth=5,font=("Ariel",12))

# the main conversion
def call_convert(rlabel1, rlabe12, inputn):
    tem = inputn.get()
    if  (inputn.get()!=""):
        M=['1','2','3','4','5','6','7','8','9','0','.',' ','-']
        for i in inputn.get():
            if i not in M:
                tkinter.messagebox.showerror("Error !!", " Please Enter numeric value.")
                break
        
    elif True:
        count=0
        for i in inputn.get():
            if i=='.':
                count+=1
        if count>1:
            tkinter.messagebox.showerror("Error !!", " Please Enter only one decimal point.")    
    if (inputn.get() == "" ):
        tkinter.messagebox.showerror("Error !!", "Temperature Not Entered.\n Please Enter Temperature.")
    if var.get() == 'Unit':
        tkinter.messagebox.showerror("Error !!", "Temperature Unit Not selected .\n Please select a given Temperature unit.")
    if tempVal == 'Celsius':
        f = float((float(tem) * 9 / 5) + 32)
        k = float((float(tem) + 273.15))
        rlabel1.insert(0,"%f Fahrenheit" % f)
        rlabe12.insert(0,"%f Kelvin" % k)
    if tempVal == 'Fahrenheit':
        c = float((float(tem) - 32) * 5 / 9)
        k = c + 273
        rlabel1.insert(0,"%f Celsius" % c)
        rlabe12.insert(0,"%f Kelvin" % k)
    if tempVal == 'Kelvin':
        c = float((float(tem) - 273.15))
        f = float((float(tem) - 273.15) * 1.8000 + 32.00)
        rlabel1.insert(0,"%f Celsius" % c)
        rlabe12.insert(0,"%f Fahrenheit" % f)
    return



# result Entry for showing the other two temperatures
result_entry1 = Entry(temperature_frame,fg="black",relief=RAISED,font=('Ariel',12),borderwidth=8)
result_entry1.pack(padx=10,pady=10)
result_entry2 = Entry(temperature_frame,fg="black",relief=RAISED,font=('Ariel',12),borderwidth=8)
result_entry2.pack(padx=10,pady=10)

call_convert = partial(call_convert, result_entry1, result_entry2, numberInput)
result_button = Button(temperature_frame, text="Convert", command=call_convert,font=("Ariel",10),bg='black',fg='light blue',relief=RAISED,borderwidth=8)
result_button.pack(padx=20, pady=40)


def clear_a():
    result_entry1.delete(0, END)
    result_entry2.delete(0, END)
    input_entry.delete(0, END)

clearB=Button(temperature_frame,font=('arial', 10), text="   Clear All  ", padx=2, pady=2, bg="black", fg="light blue",command=clear_a,relief=RAISED,borderwidth=8)
clearB.pack()

tempcurrency_button=Button(temperature_frame,font=('arial',10),text=" Currency Conversion ",padx=2, pady=2, bg="black", fg="light blue",command=Currency,relief=RAISED,borderwidth=8)
tempcurrency_button.pack(pady=10)

Home_button1=Button(temperature_frame,font=('arial', 10), text="   Back to Home  ", padx=2, pady=2, bg="black", fg="light blue",command=Home)
Home_button1.pack(side=LEFT)


root.mainloop()
engine2.runAndWait()