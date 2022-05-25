import 'package:t2_persistencia_interna/repository/impl/TasksRepositoryImpl.dart';
import 'package:t2_persistencia_interna/service/impl/task-service_impl.dart';

class HomeController{

  get service => TasksServiceImpl(repository: TasksRepositoryimpl());

  


}