
from selenium import webdriver
from selenium.webdriver.common.keys import Keys
import time


def page_title(d):
    return d.title # page title
def current_url(d):
    return d.current_url # which url is on access
def find_element_by_xpath(d):# xpath
    return d.find_element_by_xpath('/html/body/div[1]/div[2]/div/section[2]/div[1]/div/div/div[3]/a[1]').click()
def find_element_by_link_text(d):# find by text
    return d.find_element_by_link_text('Web Dev').click()
def back(d):# go back
    return d.back()
def forward(d): #go forward
    return d.forward()



# main function
driver = webdriver.Firefox(executable_path="c:/Sel_Firefox/geckodriver.exe")
driver.get('https:/www.upwork.com')
print("visiting upwork:")
print("")

test =page_title(driver) #going to first page  and print title of first page
print("title of first page:", end=":")
print(test)
print("")

test2 = current_url(driver)#going to first page  and print url of first page
print("URL of first page:", end=":")
print(test2)
print("")

find_element_by_xpath(driver) #going to 2nd page  and print url of 2nd page
test3 = current_url(driver)
print("URL of 2nd page by finding xpath:", end=":")
print(test3)
print("")

back(driver)# going back 1 step ( 1st page ) and printing the url
test4 = current_url(driver)
print("going 1 step back and printing URL of 1st page:", end=":")
print(test4)
time.sleep(3)
print("")

find_element_by_link_text(driver)
test5 = current_url(driver)
print("URL of 3rd page by finding link text:", end=":")
print(test5)
time.sleep(3)
print("")

back(driver)# going back 1 step ( 1st page ) and printing the url
test6 = current_url(driver)
print("going 1 step back and printing URL of 1st page:", end=":")
print(test6)
time.sleep(3)
print("")

forward(driver)# going back 1 step ( 1st page ) and printing the url
test6 = current_url(driver)
print("going 1 step forward and printing URL of 3rd page:", end=":")
print(test6)
time.sleep(3)
print("")

driver.quit()






