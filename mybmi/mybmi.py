#Tayseer Edouni
#Assignment 1


import math 

##############################
def BMI( units, height, weight ):
        if units == 'U':
            bmi =  (float(weight)/(float(height)**2))*703  
        else:
            bmi = (float(weight))/(float(height)**2)
                 
        return bmi
##############################        
def BMR ( units, height, weight, age, sex ) :
                                                                                          
         
         if units == 'U':                                                                                                    #US customary units
            weightKg = float(weight)*0.453592                                                                                #Converts lbs to kg
            heightM = float(height)*2.54
            if sex == "M":
                    P = (13.397*weightKg)+(4.799*heightM)-(5.677*float(age))+88.362                                         
                    
            else:
                    P = (9.247*weightKg)+(3.098*heightM)-(4.330*float(age))+447.593                                           
                    
         else:                                                                                                               #Metric System
            if sex == "M":
                   P = (13.397*float(weight))+(4.799*100*float(height))-(5.677*float(age))+88.362                              
                   
            else:
                   P = (9.247*float(weight))+(3.098*100*float(height))-(4.330*float(age))+447.593                              
                   
         return  P                                                                                                  
##############################                
def reportAnalysis(units,bmi,bmr):
        if bmi < 16.00:
            if units == "U":
                print("Your BMI is: {} (lb/in^2)\nYou fit in the Severe Thinness category".format(round(bmi,2)))
                print("To maintain your current weight you must consume {} calories per day".format(round(bmr,2)))
                print("In order to fit into the Moderate Thinness category you should consume {} calories per day (1 lb/week)".format(round(bmr,2)+500))
            else:
                print("Your BMI is: {} (kg/m^2)\nYou fit in the Severe Thinness category".format(round(bmi,2)))
                print("To maintain your current weight you must consume {} calories per day".format(round(bmr,2)))
                print("In order to fit into the Moderate Thinness category you should consume {} kcal per day (0.45 kg/week)".format(round(bmr,2)+500))
                
        
        elif 16.00 < bmi < 16.99:
            if units == "U":
                print("Your BMI is: {} (lb/in^2)\nYou fit in the Moderate Thinness category".format(round(bmi,2)))
                print("To maintain your current weight you must consume {} calories per day".format(round(bmr,2)))
                print("In order to fit into the Mild Thinness category you should consume {} calories per day (1 lb/week)".format(round(bmr,2)+500))
                print("In order to fit into the Severe Thinness category you should consume {} calories per day (1 lb/week)".format(round(bmr,2)-500))
                
            else:
                print("Your BMI is: {} (kg/m^2)\nYou fit in the Moderate Thinness category".format(round(bmi,2)))
                print("To maintain your current weight you must consume {} calories per day".format(round(bmr,2)))
                print("In order to fit into the Mild Thinness category you should consume {} kcal per day (0.45 kg/week)".format(round(bmr,2)+500))
                print("In order to fit into the Severe Thinness category you should consume {} kcal per day (0.45 kg/week)".format(round(bmr,2)-500))
                
                        
        elif 17.00 < bmi < 18.49:
            if units == "U":
                print("Your BMI is: {} (lb/in^2)\nYou fit in the Mild Thinness category".format(round(bmi,2)))
                print("To maintain your current weight you must consume {} calories per day".format(round(bmr,2)))
                print("In order to fit into the Normal category you should consume {} calories per day (1 lb/week)".format(round(bmr,2)+500))
                print("In order to fit into the Moderate Thinness category you should consume {} calories per day (1 lb/week)".format(round(bmr,2)-500))
                
            else:
                print("Your BMI is: {} (kg/m^2)\nYou fit in the Mild Thinness category".format(round(bmi,2)))
                print("To maintain your current weight you must consume {} calories per day".format(round(bmr,2)))
                print("In order to fit into the Normal category you should consume {} kcal per day (0.45 kg/week)".format(round(bmr,2)+500))
                print("In order to fit into the Moderate Thinness category you should consume {} kcal per day (0.45 kg/week)".format(round(bmr,2)-500))
                
                        
        elif 18.50 < bmi < 24.99:
            if units == "U":
                print("Your BMI is: {} (lb/in^2)\nYou fit in the Normal  category".format(round(bmi,2)))
                print("To maintain your current weight you must consume {} calories per day".format(round(bmr,2)))
                print("In order to fit into the Overweight category you should consume {} calories per day (1 lb/week)".format(round(bmr,2)+500))
                print("In order to fit into the Mild Thinness category you should consume {} calories per day (1 lb/week)".format(round(bmr,2)-500))
                
            else:
                print("Your BMI is: {} (kg/m^2)\nYou fit in the Normal  category".format(round(bmi,2)))
                print("To maintain your current weight you must consume {} calories per day".format(round(bmr,2)))
                print("In order to fit into the Overweight category you should consume {} kcal per day (0.45 kg/week)".format(round(bmr,2)+500))
                print("In order to fit into the Mild Thinness category you should consume {} kcal per day (0.45 kg/week)".format(round(bmr,2)-500))
                
                        
        elif   25.00 < bmi < 29.99:
            if units == "U":
                print("Your BMI is: {} (lb/in^2)\nYou fit in the Overweight category".format(round(bmi,2)))
                print("To maintain your current weight you must consume {} calories per day".format(round(bmr,2)))
                print("In order to fit into the Obese Class I (moderate) category you should consume {} calories per day (1 lb/week)".format(round(bmr,2)+500))
                print("In order to fit into the Normal category you should consume {} calories per day (1 lb/week)".format(round(bmr,2)-500))
                
                
            else:
                print("Your BMI is: {} (kg/m^2)\nYou fit in the Overweight category".format(round(bmi,2)))
                print("To maintain your current weight you must consume {} calories per day".format(round(bmr,2)))
                print("In order to fit into the Obese Class I (moderate) category you should consume {} kcal per day (0.45 kg/week)".format(round(bmr,2)+500))
                print("In order to fit into the Normal category you should consume {} kcal per day (0.45 kg/week)".format(round(bmr,2)-500))
                
                        
        elif  30.00 < bmi  < 34.99:
            if units == "U":
                print("Your BMI is: {} (lb/in^2)\nYou fit in the Obese Class I (Moderate) category".format(round(bmi,2)))
                print("To maintain your current weight you must consume {} calories per day".format(round(bmr,2)))
                print("In order to fit into the Obese Class II (severe) category you should consume {} calories per day (1 lb/week)".format(round(bmr,2)+500))
                print("In order to fit into the Obese Overweight category you should consume {} calories per day (1 lb/week)".format(round(bmr,2)-500))
                
            else:
                print("Your BMI is: {} (kg/m^2)\nYou fit in the Obese Class I (Moderate) category".format(round(bmi,2)))
                print("To maintain your current weight you must consume {} calories per day".format(round(bmr,2)))
                print("In order to fit into the Obese Class II (severe) category you should consume {} kcal per day (0.45 kg/week)".format(round(bmr,2)+500))
                print("In order to fit into the Obese Overweight category you should consume {} kcal per day (0.45 kg/week)".format(round(bmr,2)-500))
                
        elif 35 < bmi < 39.99:
            if units == "U":
                print("Your BMI is: {} (lb/in^2)\nYou fit in the Obese Class II (Severe) category".format(round(bmi,2)))
                print("To maintain your current weight you must consume {} calories per day".format(round(bmr,2)))
                print("In order to fit into the Obese Class III (Very Severe) category you should consume {} calories per day (1 lb/week)".format(round(bmr,2)+500))
                print("In order to fit into the Obese Class I (Moderate) category you should consume {} calories per day (1 lb/week)".format(round(bmr,2)-500))
            else:
                print("Your BMI is: {} (kg/m^2)\nYou fit in the Obese Class II (Severe) category".format(round(bmi,2)))
                print("To maintain your current weight you must consume {} calories per day".format(round(bmr,2)))
                print("In order to fit into the Obese Class III (Very Severe) category you should consume {} kcal per day (0.45 kg/week)".format(round(bmr,2)+500))
                print("In order to fit into the Obese Class I (Moderate) category you should consume {} kcal per day (0.45 kg/week)".format(round(bmr,2)-500))
                            
        else:
            if units == "U":
                print("Your BMI is: {} (lb/in^2)\nYou fit in the Obese Class III (Very Severe) category".format(round(bmi,2)))
                print("To maintain your current weight you must consume {} calories per day".format(round(bmr,2)))
                print("In order to fit into the Obese Class II (Severe) category you should consume {} calories per day (1 lb/week)".format(round(bmr,2)-500))
            else:
                print("Your BMI is: {} (kg/m^2)\nYou fit in the Obese Class III (Very Severe) category".format(round(bmi,2)))
                print("To maintain your current weight you must consume {} calories per day".format(round(bmr,2)))
                print("In order to fit into the Obese Class II (Severe) category you should consume {} kcal per day (0.45 kg/week)".format(round(bmr,2)-500))
                                     
        return
##############################
#START OF PROGRAM    
##############################

def main():
    
    while True:   
        units = input("If your preference is US customary units enter 'U' otherwise 'M' for Metric system ")    
        sex = input("Enter M or F for your gender: ")
        age = input("Enter your age in years: ")

        if units == 'U':
            height = input("Enter your height (inches): ")
            weight = input("Enter your weight (lbs): ")
        else:
            height = input("Enter your height (meters): ")
            weight = input("Enter your weight (kg): ")
    
        bmi = BMI(units,height,weight)
        bmr = BMR(units,height,weight,age,sex)
        reportAnalysis(units,bmi,bmr)
        continueVariable = input("\nWould you like to continue (Y/N)? ")
        if continueVariable == 'N' or continueVariable == 'n':
            print('Program ending')
            return False
        else:
            print('\n\n')
    
if __name__ == '__main__':
    main()
