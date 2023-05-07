from rich import print
from rich.table import Table
import os
import math

def convert_size(size_bytes):
    """this function convert bytes integer into short readable string (14.5 MB for example)"""
    if size_bytes == 0:
        return "0 B"
    size_name = ("B", "KB", "MB", "GB", "TB", "PB", "EB", "ZB", "YB")
    i = int(math.floor(math.log(size_bytes, 1024)))
    p = math.pow(1024, i)
    s = round(size_bytes / p, 2)
    return "%s %s" % (s, size_name[i])

def files_types_and_count(path) :
    """this function return available extensions , directories count , size of each extension"""
    extensions = {}
    directories = 0
    sizes = {}

    for root, dirs , files in os.walk(path) :
        for file in files :
            file = str(file)

            try :
                # separate filename from extension :
                if '.' not in file :
                    filename , extension = file , ''

                elif file.startswith('.') :
                    filename , extension = '' , file[1:]

                else :
                    file_components = file.split('.')
                    filename , extension = file_components[:-1] , file_components[-1]

                # then count :
                if extension in extensions :
                    extensions[extension] += 1
                    sizes[extension] += os.path.getsize(os.path.join(root,file))
                else :
                    extensions[extension] = 1
                    sizes[extension] = os.path.getsize(os.path.join(root,file))
            except : pass

        for _ in dirs :
            directories += 1

    if '' in extensions.keys() :
        extensions['NO EXTENSION'] = extensions['']
        sizes['NO EXTENSION'] = sizes['']
        del extensions[''] , sizes['']

    return extensions , directories , sizes

def print_statistics(path) :
    """this function print the statistics table using rich module in beatiful situation"""
    statistics , total_directories , sizes = files_types_and_count(path)
    total_files = sum(statistics.values())

    items = list(statistics.keys())
    items.sort()

    print(f'in [yellow]{path}[/yellow] there is')
    print('total files :',total_files)
    print('total folders :',total_directories)

    table = Table()

    # colons :
    table.add_column('[green]extensions')
    table.add_column('[cyan]count')
    table.add_column('[blue]size')
    table.add_column('[red]order by count : [yellow]count')
    table.add_column('[magenta]order by size  : [yellow]size')

    sum_sizes = sum(sizes.values())
    sum_statistics_100 = 100/sum(statistics.values())
    sum_sizes_100 = 100/sum_sizes

    for item , ext_count , ext_size in zip(items , sorted(statistics.items() , key=lambda x:x[1])[::-1] , sorted(sizes.items() , key=lambda x:x[1])[::-1]) :
        file_type , count = ext_count
        file_type_s , size = ext_size

        table.add_row(
            '[bold green]'+f'{item}' ,                                                                                                                          # extensions
            '[bold cyan]'+str(statistics[item]) ,                                                                                                               # count       
            convert_size(sizes[item]) ,                                                                                                                         # size
            f'[bold red]{file_type} : [bold yellow]{count} : [bold cyan] {str(count*sum_statistics_100)[:5]} %',                                                # order_by_count
            f'[bold red]{file_type_s} : [bold yellow]{convert_size(size)} : [bold cyan] {str(size*sum_sizes_100)[:5]} %',                                       # order_by_size :
            )

        table.add_section()

    table.add_row(str(len(items)) , str(total_files), convert_size(sum_sizes)  , '100 %' , '[bold green]menthioned')
    print(table)

print_statistics(R'C:\Users\BOZ')
    
