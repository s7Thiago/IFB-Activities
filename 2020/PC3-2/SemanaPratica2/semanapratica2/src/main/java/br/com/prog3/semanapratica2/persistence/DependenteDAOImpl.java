package br.com.prog3.semanapratica2.persistence;

import java.util.List;

import org.hibernate.Session;
import org.hibernate.SessionFactory;

import br.com.prog3.semanapratica2.controller.DependenteController;
import br.com.prog3.semanapratica2.model.Dependente;
import br.com.prog3.semanapratica2.util.HibernateUtil;

public class DependenteDAOImpl implements DependenteDAO {

    private Session session;

    @Override
    public void incluir(Dependente dependente) {
        session = null;

        try {
            SessionFactory sessionFactory = HibernateUtil.getSessionFactory();

            session = sessionFactory.openSession();
            session.beginTransaction();
            session.save(dependente);
            session.getTransaction().commit();

        } catch (Exception e) {
            if (session != null) {
                session.getTransaction().rollback();
            }
            e.printStackTrace();
        } finally {
            if (session != null) {
                session.close();
            }
        }
    }

    @Override
    public void alterar(Dependente dependente) {
        session = null;

        try {
            SessionFactory sessionFactory = HibernateUtil.getSessionFactory();

            session = sessionFactory.openSession();
            session.beginTransaction();
            session.update(dependente);
            session.getTransaction().commit();

        } catch (Exception e) {
            if (session != null) {
                session.getTransaction().rollback();
            }
            e.printStackTrace();
        } finally {
            if (session != null) {
                session.close();
            }
        }
    }

    @Override
    public void excluir(Dependente dependente) {

        session = null;

        try {
            SessionFactory sessionFactory = HibernateUtil.getSessionFactory();

            session = sessionFactory.openSession();
            session.beginTransaction();
            session.delete(dependente);
            session.getTransaction().commit();

        } catch (Exception e) {
            if (session != null) {
                session.getTransaction().rollback();
            }
            e.printStackTrace();
        } finally {
            if (session != null) {
                session.close();
            }
        }

    }

    @Override
    public List<Dependente> listarTodos() {

        session = null;
        List<Dependente> lista = null;

        try {
            SessionFactory sessionFactory = HibernateUtil.getSessionFactory();

            session = sessionFactory.openSession();
            session.beginTransaction();
            lista = (List<Dependente>) session.createQuery("from empregado").list();
            session.getTransaction().commit();

        } catch (Exception e) {
            if (session != null) {
                session.getTransaction().rollback();
            }
            e.printStackTrace();
        } finally {
            if (session != null) {
                session.close();
            }
        }

        return lista;
    }

}
