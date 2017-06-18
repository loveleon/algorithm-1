#!/usr/bin/python
# -*- coding: utf-8 -*-
import os
def del_files(path):
	for root , dirs, files in os.walk(path):
		for name in files:
			if name.endswith(".vcxproj"):#.vcxproj .filters
				os.remove(os.path.join(root, name))
				print ("Delete File: " + os.path.join(root, name))
# test
if __name__ == "__main__":
	path = '/code/algorithm/offer_CodingInterviewChinese2/CodingInterviewChinese2'
	del_files(path)

