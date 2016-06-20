from django.shortcuts import render
from django.http import HttpResponse


def ajaxtest(request):
    if request.is_ajax():
        data = "You click " + request.GET['click'] + " button"
        import json
        return HttpResponse(json.dumps({'message':data}), 'application/json')
    return render(request, 'ajaxtest.html')
