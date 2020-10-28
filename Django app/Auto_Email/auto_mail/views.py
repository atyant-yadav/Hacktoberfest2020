from django.shortcuts import render,get_object_or_404,redirect
from django.views import generic
from django.contrib.auth.mixins import LoginRequiredMixin
from django.urls import reverse_lazy, reverse
from . import models
from . import forms
from django.utils import timezone
from django.contrib.auth.decorators import login_required
from django.core.mail import send_mail
from django.contrib.auth import get_user_model
# Create your views here.

User = get_user_model()

class MailCreationView(generic.CreateView,LoginRequiredMixin):
    login_url = '/login/'
    template_name = 'auto_mail/mail.html'
    model = models.Mail
    form_class = forms.MailCreationForm

    def get_success_url(self):
        return reverse('auto_mail:detail',kwargs={'pk':self.object.pk})

class MailListView(generic.ListView,LoginRequiredMixin):
    login_url = '/login/'
    template_name = 'auto_mail/mail_list.html'
    context_object_name = 'mail_list_content'

    def get_queryset(self):
        return models.Mail.objects.filter(created_on__lte=timezone.now()).order_by('-created_on')

class MailDetailView(LoginRequiredMixin,generic.DetailView):
    login_url = '/login/'
    template_name = 'auto_mail/mail_detail.html'
    model = models.Mail

@login_required
def post(request,pk):
    # mail = get_object_or_404(models.Mail,pk=pk)
    Subject = models.Mail.objects.get(pk=pk).subject
    Message = models.Mail.objects.get(pk=pk).message
    emails = User.objects.filter(is_active=True).values_list('email', flat=True)
    send_mail(Subject,Message,'djangospare@gmail.com',emails,fail_silently=False)

    return redirect('success')