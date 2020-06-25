def is_int(value) -> bool:
    try:
        int(value)

        return True
    except:
        return False

def is_float(value) -> bool:
    try:
        float(value)

        return True
    except:
        return False
