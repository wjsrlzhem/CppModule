# c++ 모듈 사용 하기


#모듈 위치 설정
'''
import sys
sys.path.append("C:\\Users\\arist\\Desktop\\")

'''
import CppModule as CM

print("CppModule_start() : ", CM.start("test command"))
print(CM.add(1,3))
print(CM.mul(2,4))
