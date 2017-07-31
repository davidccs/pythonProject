
class Employee:
    #init is initiliase
    def __init__(self, first, last, pay):
        self.first = first
        self.last = last
        self.pay = pay
        self.email = first + '.' + last + '@company.com'

    def fullname(self):
        return '{} {}'.format(self.first, self.last)

#instance
emp_1 = Employee('David', 'Scafer', 50000)
emp_2 = Employee('Test', 'User', 60000)

#print(emp_2.fullname())

print(Employee.fullname(emp_1))
