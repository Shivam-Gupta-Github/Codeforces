def translate(commands):
    python_code = []
    indentation = 0

    for command in commands:
        if command.startswith("for "):
            times = int(command.split()[1])
            python_code.append(" " * indentation + f"for i in range({times}):")
            indentation += 4
        elif command == "do":
            continue
        elif command == "done":
            indentation -= 4
        elif command.startswith("print "):
            statement = command.split(" ", 1)[1]
            python_code.append(" " * indentation + f"print({statement})")
        elif command.startswith("break "):
            n = int(command.split()[1])
            python_code.append(" " * indentation + f"if i == {n - 1}: break")
        elif command.startswith("continue "):
            n = int(command.split()[1])
            python_code.append(" " * indentation + f"if i == {n - 1}: continue")
    
    return "\n".join(python_code)

if __name__ == "__main__":
    n = int(input())
    commands = [input().strip() for i in range(n)]
    
    # Convert commands to Python code
    python_code = translate(commands)

    exec(python_code)

