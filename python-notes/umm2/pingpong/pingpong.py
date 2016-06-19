class Pingpong():

    @staticmethod
    def is_change(index):
        if (index % 7) == 0:
            return True
        if str(index).find('7') != -1:
            return True
        return False
