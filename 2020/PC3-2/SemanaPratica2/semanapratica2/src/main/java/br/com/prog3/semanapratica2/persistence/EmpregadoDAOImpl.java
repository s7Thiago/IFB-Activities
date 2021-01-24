package br.com.prog3.semanapratica2.persistence;

import java.util.List;

import org.hibernate.Session;
import org.hibernate.SessionFactory;

import br.com.prog3.semanapratica2.model.Empregado;
import br.com.prog3.semanapratica2.util.HibernateUtil;

public class EmpregadoDAOImpl implements EmpregadoDAO {

    private Session session;

    @Override
    public void incluir(Empregado empregado) {
        session = null;

        try {
            SessionFactory sessionFactory = HibernateUtil.getSessionFactory();

            session = sessionFactory.openSession();
            session.beginTransaction();
            session.save(empregado);
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
    public void alterar(Empregado empregado) {
        session = null;

        try {
            SessionFactory sessionFactory = HibernateUtil.getSessionFactory();

            session = sessionFactory.openSession();
            session.beginTransaction();
            session.update(empregado);
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
    public void excluir(Empregado empregado) {
        session = null;

        try {
            SessionFactory sessionFactory = HibernateUtil.getSessionFactory();

            session = sessionFactory.openSession();
            session.beginTransaction();
            session.delete(empregado);
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
    public List<Empregado> listarTodos() {

        session = null;
        List<Empregado> lista = null;

        try {
            SessionFactory sessionFactory = HibernateUtil.getSessionFactory();

            session = sessionFactory.openSession();
            session.beginTransaction();
            lista = (List<Empregado>) session.createQuery("from empregado").list();
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

    @Override
    public Empregado buscarPeloCpf(String cpf) {

        session = null;
        Empregado empregado = new Empregado();

        try {
            SessionFactory sessionFactory = HibernateUtil.getSessionFactory();

            session = sessionFactory.openSession();
            session.beginTransaction();

            empregado = (Empregado) session.load(Empregado.class, cpf);
            session.save(empregado);

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

        return empregado;
    }

}
