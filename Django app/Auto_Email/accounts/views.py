from django.shortcuts import render
from django.views import generic
from django.urls import reverse_lazy
from . import forms
# Create your views here.


class SignUpView(generic.CreateView):  
    form_class = forms.UserSignUpForm
    success_url = reverse_lazy('accounts:login')
    template_name = 'accounts/sign_up.html'