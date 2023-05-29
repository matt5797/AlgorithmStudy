def solution(phone_book):
    answer = True
    phone_dict = dict().fromkeys(phone_book)
    for phone in phone_dict.keys():
        for length in range(len(phone)):
            prefix = str(phone[:length+1])
            if phone_dict.get(prefix, "fail")!="fail" and prefix != phone:
                answer = False
    return answer