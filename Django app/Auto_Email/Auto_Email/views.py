from django.views import generic


class Thanks(generic.TemplateView):
    template_name = 'thanks.html'

class Index(generic.TemplateView):
    template_name = 'index.html'

class Success(generic.TemplateView):
    template_name = 'success.html'