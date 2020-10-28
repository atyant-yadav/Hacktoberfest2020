from django import forms
from . import models

class MailCreationForm(forms.ModelForm):
    class Meta:
        model = models.Mail
        fields = ('subject','message')