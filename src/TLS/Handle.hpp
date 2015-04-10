/*
 * File:   Handle.hpp
 * Author: JoPe
 *
 * Created on 2 de abril de 2015, 11:36
 */

#ifndef HANDLE_HPP
#define	HANDLE_HPP

namespace tls
{
  template <class Resource, void CleanUp(Resource r)>
  class Handle
  {
    Resource m_resource;

    public:
      Handle(Resource resource = Resource{}) noexcept;
      Handle(Handle&& handle) noexcept;
      Handle& operator=(Resource resource) noexcept;
      Handle& operator=(Handle&& handle) noexcept;
      operator Resource() const noexcept;
      ~Handle() noexcept;

      friend void swap(Handle& lhs, Handle& rhs) noexcept
      {
        auto resource = lhs.m_resource;
        lhs.m_resource = rhs.m_resource;
        rhs.m_resource = resource;
      }
  };

  template <class Resource, void CleanUp(Resource r)>
  Handle<Resource, CleanUp>::Handle(Resource resource) noexcept
    : m_resource(resource)
  {}

  template <class Resource, void CleanUp(Resource r)>
  Handle<Resource, CleanUp>::~Handle() noexcept
  {
    CleanUp(m_resource);
  }

  template <class Resource, void CleanUp(Resource r)>
  Handle<Resource, CleanUp>::operator Resource() const noexcept
  {
    return m_resource;
  }

  template <class Resource, void CleanUp(Resource r)>
  Handle<Resource, CleanUp>::Handle(Handle&& handle) noexcept
    : m_resource(handle.m_resource)
  {
    handle.m_resource = Resource{};
  }

  template <class Resource, void CleanUp(Resource r)>
  Handle<Resource, CleanUp>& Handle<Resource, CleanUp>::operator=(
      Handle&& handle) noexcept
  {
    CleanUp(m_resource);
    m_resource = handle.m_resource;
    handle.m_resource = Resource{};
    return *this;
  }

  template <class Resource, void CleanUp(Resource r)>
  Handle<Resource, CleanUp>& Handle<Resource, CleanUp>::operator=(
      Resource resource) noexcept
  {
    CleanUp(m_resource);
    m_resource = resource;
    return *this;
  }
}

#endif	/* HANDLE_HPP */

