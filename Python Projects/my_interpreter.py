"""
BOUZID COPY-RIGHT : ALL RIGHTS RESERVERD .
"""
import os
bcolors = {
    'purple' : f'\033[95m',
    'blue' : f'\033[94m',
    'cyan' : f'\033[96m',
    'green' : f'\033[92m',
    'yellow' : f'\033[93m',
    'red' : f'\033[91m',
    'white' : f'\033[0m',
    'bold' : f'\033[1m',
    'underline' : '\033[4m'
    }
os.system('cls')
user_input = str()
code_string = str()
writing_color = input(f'''
choose writing color : ( press enter to get default color )
    white |{bcolors['yellow']} yellow |{bcolors['green']} green |{bcolors['blue']} blue |{bcolors['cyan']} cyan |{bcolors['purple']} purple |{bcolors['red']} red |{bcolors['white']}
=> ''')
output_color = input(f'''
choose output color : ( press enter to get default color )
    white |{bcolors['yellow']} yellow |{bcolors['green']} green |{bcolors['blue']} blue |{bcolors['cyan']} cyan |{bcolors['purple']} purple |{bcolors['red']} red |{bcolors['white']}
=> ''')
os.system('cls')
print(bcolors['yellow']+'Bouzid interpreter :\n')
def start_again(color1) :
    global user_input , code_string
    user_input = input(bcolors['yellow']+'>> '+color1)
    code_string = user_input

if writing_color not in bcolors :
    writing_color = 'white'
if output_color not in bcolors :
    output_color = 'green'
start_again(bcolors[writing_color])
continue_var = True
while continue_var :

        if user_input =='quit' :
            continue_var = False
            continue
        elif  not code_string.endswith(':') and not user_input.startswith('\t') :
                try :   
                    print(bcolors[output_color],end='') # changing color to output color
                    exec(compile(code_string,'sumstring','exec'))
                    start_again(bcolors[writing_color])
                except :
                    print(bcolors['red']+'ERROR , Check your code '+bcolors['yellow']+'(^_^) '+bcolors['yellow']) #print error in red
                    start_again(bcolors[writing_color])
                finally :
                    continue
        else :
            pass
        user_input = input(' '*3)
        code_string+='\n'+user_input
os.system('cls')
print(bcolors['green'],'Big thanks to use my application',bcolors['yellow'],'(^_^) \n')
# with '\t' with ':' => wait
# not '\t' with ':' => wait
# with '\t' not ':' => wait
# not '\t' not ':' => run