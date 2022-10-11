from selenium import webdriver
# from selenium.webdriver.chrome.options import Options
from selenium.webdriver.chrome.service import Service
import pandas as pd
#Automate Udemy

website="https://www.udemy.com/courses/search/?src=ukw&q=react"
path="C:\\Users\\mahad\\OneDrive\\Desktop\\To-Do List\\chromedriver.exe"

#Headless Mode
# options=Options()
# options.headless=True

service=Service(executable_path=path)
driver=webdriver.Chrome(service=service)

driver.get(website)

header=[]
desc=[]
rating=[]
links=[]

courses=driver.find_elements(by="xpath",value='//div[@class="course-card--main-content--2XqiY course-card--has-price-text--1c0ze"]')

for course in courses:
    course_header=course.find_element(by="xpath",value="./h3").text
    course_desc=course.find_element(by="xpath",value="./p").text
    course_rating=course.find_element(by="xpath",value='./div[@class="course-card--row--29Y0w"]/span/span[@class="udlite-heading-sm star-rating--rating-number--2o8YM"]').text
    course_link=course.find_element(by="xpath",value="./h3/a").get_attribute("href")
    
    header.append(course_header)
    desc.append(course_desc)
    rating.append(course_rating)
    links.append(course_link)

my_dict={
    "Course":header,
    "Description":desc,
    "Rating":rating,
    "Link":links
}

final_path="C:\\Users\\mahad\\OneDrive\\Desktop\\To-Do List\\Automation\\CourseAutomation\\"
frame=pd.DataFrame(my_dict)
frame.to_csv(final_path+'React.csv')

driver.quit()