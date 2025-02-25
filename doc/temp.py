import os

def print_hierarchy(path, indent=0):
    """Recursively print the directory hierarchy."""
    for item in os.listdir(path):
        item_path = os.path.join(path, item)
        print(' ' * indent + '|-- ' + item)
        if os.path.isdir(item_path):
            print_hierarchy(item_path, indent + 4)

if __name__ == "__main__":
    directory_path = "C:\\Users\\Dell\\OneDrive - Sudhir Srivastava Innovations Pvt. Ltd\\Abhinay's Workspace\\GitHub Repo\\Drivers\\lib"
    print_hierarchy(directory_path)
