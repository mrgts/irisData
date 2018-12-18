# -*- coding: utf-8 -*-
"""
Created on Sat Sep 29 19:26:00 2018

@author: MrGTS
"""
import flask
import pymongo
import json
import serial, time

arduino = serial.Serial('COM8', 9600)

while True:
    time.sleep(4)
    rawString = arduino.readline()
    rawString = rawString.decode("utf-8")
    rawString = rawString.replace("'", "\"")
    json_data = json.loads(rawString)

    if arduino.isOpen():

        from pymongo import MongoClient

        client = MongoClient('mongodb://#############')

        db = client['mrgts_iris']

        collection = db['especies']

        medida = json_data

        collection.insert_one(medida)

        for medida in collection.find():
            id = medida['_id']
            nodo = medida['nodo']
            sl = medida['sl']
            sw = medida['sw']
            pl = medida['pl']
            pw = medida['pw']

            print('----')
            print(id)
            print(nodo)
            print(sl)
            print(sw)
            print(pl)
            print(pw)

arduino.close()